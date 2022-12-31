import React from "react";
import '../time.css';
import { AiOutlineStar, AiOutlineFileGif, AiOutlineFieldTime } from 'react-icons/ai';
import { BsCardImage } from 'react-icons/bs';
import { RiEmotionLine, RiGpsLine } from 'react-icons/ri';
import { ImParagraphLeft } from 'react-icons/im';
import { BsList } from 'react-icons/bs'
import { AiOutlineRetweet } from 'react-icons/ai';
import { AiOutlineHeart } from 'react-icons/ai';
import { MdIosShare } from 'react-icons/md';
import { ImBubble } from 'react-icons/im';


export default function HomePage() {
    const [count, setCount] = React.useState(0);
    const [count2, setCount2] = React.useState(0);
    const [count3, setCount3] = React.useState(0);
    const [fileImage, setFileImage] = React.useState("");

    const onClick = () => {
        setCount(count + 1);
    }

    const onClick2 = () => {
        setCount2(count2 + 1);
    }

    const onClick3 = () => {
        setCount3(count3 + 1);
    }
    
    const [content, setContent] = React.useState({
        content: ''
    })

    const getValue = e => {
        const { value, name } = e.target;
        setContent({
            ...content,
            [name]: value
        })
        console.log(content);
    };

    const [viewContent, setViewContent] = React.useState([])

    const saveFileImage = (e) => {
        setFileImage(URL.createObjectURL(e.target.files[0]));
    };

    return (
        <div className="TimeLinePage">
            <div className="header-page">
                <header>
                    <span id="head-text">홈</span>
                    <AiOutlineStar id="head-icon" />
                </header>
            </div>
            <div className="twitPage">
                <div>
                    <img src="./img/profile-imgs.png" />
                    <input type="text"
                    id="twit-text"
                    placeholder="무슨 일이 일어나고 있나요?"
                    onChange={getValue} 
                    name="content"></input>
                </div>
                <div id="icons">
                    <label for="uploader" id="upload-icon"><BsCardImage className="icon" size="20" color="#00acee" /></label>
                    <input type="file" id="uploader" style={{ display: "none" }} onChange={saveFileImage}></input>
                    <AiOutlineFileGif className="icon" size="20" color="#00acee" />
                    <ImParagraphLeft className="icon" size="20" color="#00acee" />
                    <RiEmotionLine className="icon" size="20" color="#00acee" />
                    <AiOutlineFieldTime className="icon" size="20" color="#00acee" />
                    <RiGpsLine className="icon" size="20" color="#00acee" />
                    <button 
                    id="twit-btn"
                    onClick={() => {
                        setViewContent(viewContent.concat({...content}));
                    }}>
                        <span id="icon-text">트윗하기</span>
                    </button>
                </div>
                <div className="listPage">
                    {
                        viewContent.map(element =>
                            <div className="page">
                                <div className="image-container">
                                    <img src="./img/profile-imgs.png" />
                                </div>
                                <div className="main-container">
                                    <span id="name-text">정현우</span>
                                    <span className="page-text">@U_ID </span>
                                    <span className="page-text">6월 21일</span>
                                    <span id="page-icon"><BsList /></span>
                                    <span>{element.content}</span>
                                    {
                                        fileImage && (
                                            <img
                                                id="back-img"
                                                src={fileImage} />
                                        )
                                    }
                                    
                                </div>
                                <div className="icon-container">
                                    <button className="btn-icons-first" onClick={onClick}><span className="icons-first"><ImBubble /></span></button>
                                    <span className="icon-texts">{count}</span>
                                    <button className="btn-icons-second" onClick={onClick2}><span className="icons"><AiOutlineRetweet /></span></button>
                                    <span className="icon-texts">{count2}</span>
                                    <button className="btn-icons-second" onClick={onClick3}><span className="icons"><AiOutlineHeart /></span></button>
                                    <span className="icon-texts">{count3}</span>
                                    <button className="btn-icons-second"><span className="icons"><MdIosShare /></span></button>
                                </div>
                            </div>
                        )
                    }
                </div>
            </div>
        </div>
    );
}
