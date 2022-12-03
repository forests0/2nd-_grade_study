import styled from "styled-components"

export const Footer = () => {
    return (
        <div>
            <span>2022 BSSM Hackton Team #4 All rights Reserved</span>
        </div>
    )
}

export default Footer;

const Footerdiv = styled.div`
    div {
        border: 0.5px solid black;
    }
    span {
        color: lightgray;
        font-size: 15px;
        padding: 20px;

    }
`