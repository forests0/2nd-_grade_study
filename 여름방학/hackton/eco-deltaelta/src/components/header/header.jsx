import { BrowserRouter, Route } from 'react-router-dom';
import React from "react";
import Helper from "../body/helper"

export const Header = () => {
  return (
      <div>
          <header>
            <nav>
              <Route path="/" component={Helper} >도움요청</Route>
              <Route path="/test" component={Helper} >이벤트</Route>
              <button>테스트</button>
            </nav>
          </header>
      </div>
    )
}

export default Header;