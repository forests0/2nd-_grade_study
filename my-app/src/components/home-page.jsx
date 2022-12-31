import React from "react";
import Banner from "./banner.jsx";
import TimeLine from './timeline.jsx';
import "../styles.css";
import Trend from "./trend.jsx";

export default function HomePage() {
    const [Twit, setTwit] = React.useState("");
    const [Check, setCheck] = React.useState(false);

    const saveData = () => {
        const twitObj = { name: Twit };
        window.localStorage.setItem("Twit", JSON.stringify(twitObj));
      };
    
      const callData = () => {
        setCheck(true);
      };
    
      const onChange = (e) => {
        setTwit(e.target.value);
        setCheck(false);
      };

    return (
        <div className="Home-Page">
          <div className="Home-Header">
              <div className="name-twitlogo">
                  
                  <Banner />
              </div>
          </div>
          <div className="newTwit">
            <TimeLine />
          </div>
          <div className="serachTrend">
              <Trend />
          </div>
        </div>
    );
}
