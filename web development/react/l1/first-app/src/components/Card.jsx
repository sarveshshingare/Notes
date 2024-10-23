import React from "react";
import "../components/Card.css";
const Card = (props) => {
  return (
    <div className="cards">
      <h2>{props.title}</h2>
      <p>{props.desc}</p>
    </div>
  );
};

export default Card;
