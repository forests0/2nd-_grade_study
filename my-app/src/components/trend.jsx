import "../trend.css";
import { FiSend } from "react-icons/fi";

export default function Trend() {
    return (
        <div className="trend--div">
            <div className="search--tr">
              <input type="text" className="trend--input" />
            </div>
            <div className="trend--hash">
              <h3>나를 위한 트렌드</h3>
              <div>
                <span>대한민국에서 트렌드중</span>
                <p></p>
              </div>
            </div>
        </div>

    )
}