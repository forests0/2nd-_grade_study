import "./styles.css";
import Footer from './footer';
import { AiOutlineTwitter, AiFillApple  } from 'react-icons/ai';
import { FcGoogle } from "react-icons/fc";

export default function App() {
    function handleClick() {
        window.location.href = '/home';
    }
    return (
        <div className="react-root">
            <div className="content">
                <main className="react-main">
                    <div className="big-image">
                        <img src="img/main.png" id="image"/>
                    </div>
                    <div className="login-page">
                        <div id="icon-container">
                            <span id="icon"><AiOutlineTwitter size="50" color="#00acee" /></span>
                        </div>
                        <div id="text-bold-container">
                            <span id="text-bold">지금 일어나고 있는 일</span>
                        </div>
                        <div id="text-container">
                            <span id="text">오늘 트위터에 가입하세요.</span>
                        </div>
                        <div id="login">
                            <button id="google"><FcGoogle size="24" id="google-icon" /><sapn id="google-text">google에서 가입하기</sapn></button>
                            <p></p>
                            <button id="apple"><AiFillApple size="24" id="apple-icon" /><span id="apple-text">Apple에서 가입하기</span></button>
                        </div>
                        <div id="line-container">
                            <span>또는</span>
                        </div>
                        <div id="register-container">
                            <button id="btn"><span id="main-text">휴대폰 번호나 이메일 주소로 가입하기</span></button>
                            <span id="sub">By signing up, you agree to the Terms of Service and Privacy Policy, including Cookie Use.</span>
                        </div>
                        <div id="final-contiainer">
                            <span id="final-text">이미 트위터에 가입하셨나요?</span>
                            <p></p>
                            <button id="final-btn" onClick={handleClick}><span id="final-Subtext">로그인</span></button>
                        </div>
                    </div>
                </main>
            </div>
            <div className="Footer">
                <Footer />
            </div>
        </div>
    );
}
