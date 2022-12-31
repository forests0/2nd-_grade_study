import { AiOutlineTwitter } from 'react-icons/ai';
import '../styles.css';
//test 주석
export default function Banner() {
    return (
        <div className="Banner">
            <div className="logo-padding">
                <img src="./img/twitter-logo.png" className="banner-logo" />
            </div>
            <div className="banner-enpage">
                <div className="logo-padding">
                    <div classname="banner-indiv">
                        <img src="./img/home.png" className="banner-logo" />
                        <span className="banner-text" id="banner-home">홈</span>
                    </div>
                </div>
                <div className="logo-padding">
                    <div classname="banner-indiv">
                        <img src="./img/explore.png" className="banner-logo" />
                        <span className="banner-text">탐색하기</span>
                    </div>
                </div>
                <div className="logo-padding">
                    <div classname="banner-indiv">
                        <img src="./img/alerm.png" className="banner-logo" />
                        <span className="banner-text">알림</span>
                    </div>
                </div>
                <div className="logo-padding">
                    <div classname="banner-indiv">
                        <img src="./img/dms.png" className="banner-logo" />
                        <span className="banner-text">쪽지</span>
                    </div>
                </div>
                <div className="logo-padding">
                    <div classname="banner-indiv">
                        <img src="./img/bookmark.png" className="banner-logo" />
                        <span className="banner-text">북마크</span>
                    </div>
                </div>
                <div className="logo-padding">
                    <div classname="banner-indiv">
                        <img src="./img/list.png" className="banner-logo" />
                        <span className="banner-text">리스트</span>
                    </div>
                </div>
                <div className="logo-padding">
                    <div classname="banner-indiv">
                        <img src="./img/profile.png" className="banner-logo" />
                        <span className="banner-text">프로필</span>
                    </div>
                </div>
                <div className="logo-padding">
                    <div classname="banner-indiv">
                        <img src="./img/more.png" className="banner-logo" />
                        <span className="banner-text">더보기</span>
                    </div>
                </div>
                <div className="logo-padding">
                    <img src="./img/twit-start.png" className="banner-logos" />
                </div>
            </div>
            <div className="banner-profile">
                <div className="logo-padding">
                    <div className="profile-box1">
                        <img src="./img/profile-imgs.png" className="banner-logos" />
                    </div>
                    <div className="profile-mspan">
                        <div className="profile-span1">
                            <span className="profile-name">정현우</span>
                        </div>
                        <div className="profile-span2">
                            <span className="profile-id">@Test_godo</span>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    );
}
