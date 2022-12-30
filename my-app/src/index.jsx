import React from "react"
import ReactDOM from "react-dom"
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Main from "./app.jsx";
import Home from "./components/home-page.jsx";

ReactDOM.render(
    <BrowserRouter>
        <Routes>
            <Route path="/" element={<Main />} />
            <Route path="/home" element={<Home />} />
        </Routes>
    </BrowserRouter>
, document.getElementById("root"))
