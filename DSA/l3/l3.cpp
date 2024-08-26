// #include <iostream>
// using namespace std;

// int main()
// {
//     for (int i = 0; i < 4; i++)
//     {
//         /* code */
//         for (int j = 0; j < 4; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// Sarvesh Shingare
// 202101050031

#include <mpi.h>
#include <iostream>
#include <vector>
#include <cmath>

#define N 4                // Matrix size (NxN)
#define BLOCK_SIZE (N / 2) // Assuming a 2x2 process grid

void multiplyMatrices(const std::vector<int> &A, const std::vector<int> &B, std::vector<int> &C)
{
    for (int i = 0; i < BLOCK_SIZE; ++i)
    {
        for (int j = 0; j < BLOCK_SIZE; ++j)
        {

            for (int k = 0; k < BLOCK_SIZE; ++k)
            {
                C[i * BLOCK_SIZE + j] += A[i * BLOCK_SIZE + k] * B[k * BLOCK_SIZE + j];
            }
        }
    }
}
int main(int argc, char \*_argv)
{
    int rank, size, sqrt_p;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    sqrt_p = std::sqrt(size);
    if (sqrt_p _ sqrt * p != size || N % sqrt_p != 0)
    {
        if (rank == 0)
        {
            std::cerr << "Error: The number of processes must be a perfect square and divisible by N." << std::endl;
        }
        MPI_Finalize();
        return -1;
    }
    int subMatSize = N / sqrt_p;
    std::vector<int> A(subMatSize * subMatSize, 0);
    std::vector<int> B(subMatSize _ subMatSize, 0);
    std::vector<int> C(subMatSize _ subMatSize, 0); // Result matrix
                                                    // Initialize matrices A and B
    for (int i = 0; i < subMatSize \_ subMatSize; ++i)
    {
        A[i] = 1; // Example initialization
        B[i] = 1; // Example initialization
    }

    MPI_Comm gridComm;
    int dims[2] = {sqrt_p, sqrt_p};
    int periods[2] = {1, 1}; // Enable wrap-around (cyclic shifts)
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 1, &gridComm);

    int coords[2];
    MPI_Cart_coords(gridComm, rank, 2, coords);

    int left, right, up, down;
    MPI_Cart_shift(gridComm, 1, -1, &right, &left);
    MPI_Cart_shift(gridComm, 0, -1, &down, &up);

    // Initial alignment for A and B
    MPI *Sendrecv_replace(&A[0], subMatSize * subMatSize, MPI * INT, left, 0, right, 0, gridComm, MPI_STATUS_IGNORE);
    MPI_Sendrecv_replace(&B[0], subMatSize * subMatSize, MPI_INT, up, 0, down,
                         0, gridComm, MPI_STATUS_IGNORE);

    // Perform Cannon's algorithm iterations for (int i = 0; i < sqrt_p; ++i)
    {
        multiplyMatrices(A, B, C);

        // Shift left A
        MPI_Sendrecv_replace(&A[0], subMatSize * subMatSize, MPI_INT, left, 0, right, 0, gridComm, MPI_STATUS_IGNORE);
        // Shift up B
        MPI_Sendrecv_replace(&B[0], subMatSize * subMatSize, MPI_INT, up, 0, down,

                             0, gridComm, MPI_STATUS_IGNORE);
    }

    // Gather results at rank 0 std::vector<int> finalResult; if (rank == 0)
    {
        finalResult.resize(N _ N);
    }
    MPI_Gather(&C[0], subMatSize _ subMatSize, MPI_INT, &finalResult[0], subMatSize \* subMatSize, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        std::cout << "Result matrix:" << std::endl;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                std::cout << finalResult[i * N + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
