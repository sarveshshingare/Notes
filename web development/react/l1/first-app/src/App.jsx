import Card from "./components/Card";
import Navbar from "./components/navbar";
function App() {
  return (
    <div>
      <Navbar />
      <div className="cardsContainer">
        <Card title="Card 1" desc="this is the description for card 1" />
        <Card title="Card 2" desc="this is the description for card 2" />
        <Card title="Card 3" desc="this is the description for card 3" />
        <Card title="Card 4" desc="this is the description for card 4" />
      </div>
    </div>
  );
}

export default App;
