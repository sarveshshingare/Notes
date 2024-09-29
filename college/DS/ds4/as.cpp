#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Process
{
public:
    int id;
    bool isAlive;
    Process(int id)
    {
        this->id = id;
        this->isAlive = true;
    }
};
class RingDistributedSystem
{
public:
    vector<Process> processes;
    int coordinatorId;
    RingDistributedSystem(vector<int> ids)
    {
        for (int id : ids)
        {
            processes.push_back(Process(id));
        }
        coordinatorId = -1;
    }
    void displayProcesses()
    {
        cout << "Processes: ";
        for (auto &process : processes)
        {
            if (process.isAlive)
            {
                cout << process.id << " ";
            }
        }
        cout << endl;
    }
    void crashProcess(int id)
    {
        for (auto &process : processes)
        {
            if (process.id == id)
            {
                process.isAlive = false;
                cout << "Process " << id << " crashed." << endl;
                if (coordinatorId == id)
                {
                    cout << "Coordinator " << id << " has crashed." << endl;
                    startElection(id); // Start election by passing message
                }
                break;
            }
        }
    }
    void startElection(int initiatorId)
    {
        cout << "Election started by process " << initiatorId << "." << endl;
        vector<int> electionList;
        // Logical Ring - Collect alive processes in election list
        for (auto &process : processes)
        {
            if (process.isAlive)
            {
                electionList.push_back(process.id);
            }
        }
        if (!electionList.empty())
        {
            // Elect the highest ID as coordinator
            int newCoordinator = *max_element(electionList.begin(),
                                              electionList.end());
            coordinatorId = newCoordinator;
            cout << "Process " << newCoordinator << " is elected as the new coordinator." << endl;
        }
        else
        {
            cout << "No process available for election." << endl;
        }
    }
    void recoverProcess(int id)
    {
        for (auto &process : processes)
        {
            if (process.id == id)
            {
                process.isAlive = true;
                cout << "Process " << id << " recovered." << endl;
                if (coordinatorId == -1 || id > coordinatorId)
                {
                    startElection(id);
                }
                break;
            }
        }
    }
    void displayCoordinator()
    {
        if (coordinatorId != -1)
        {
            cout << "Current Coordinator: Process " << coordinatorId << endl;
        }
        else
        {
            cout << "No coordinator is selected." << endl;
        }
    }
};
int main()
{
    vector<int> processIds = {1, 2, 3, 4, 5}; // Process IDs in the distributed system
    RingDistributedSystem ds(processIds);
    ds.displayProcesses();
    ds.startElection(1); // Initial election started by process 1
    ds.displayCoordinator();
    ds.crashProcess(5); // Simulate crash of the coordinator
    ds.displayCoordinator();
    ds.recoverProcess(5); // Simulate recovery of a crashed process
    ds.displayCoordinator();
    return 0;
}