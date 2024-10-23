import { useEffect, useState } from "react";
import reactLogo from "./assets/react.svg";
import viteLogo from "/vite.svg";
import "./App.css";

function App() {
  const [count, setCount] = useState(0);
  const [todos, setTodos] = useState([
    {
      title: "hey 1",
      desc: "desc 1",
    },
    {
      title: "hey 2",
      desc: "desc 2",
    },
    {
      title: "hey 3",
      desc: "desc 3",
    },
    {
      title: "hey 4",
      desc: "desc 4",
    },
  ]);
  const Todo = (todo) => {
    return (
      <>
        <div className="todo">{todo.title}</div>
        <div className="todo">{todo.desc}</div>
      </>
    );
  };

  return (
    <>
      <div>
        The count is {count}
        <button
          onClick={() => {
            setCount(count + 1);
          }}
        >
          Update count
        </button>
        {todos.map((todo) => {
          return <Todo todo={todo.title} key={todo.title} />;
        })}
      </div>
    </>
  );
}

export default App;
