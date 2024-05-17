import React, { useEffect, useState, Button } from 'react';

import './About.css';
import AboutPop from './AboutPop'

function About() {
    const [text, setText] = useState('');
    const [showMore, setShowMore] = useState(false);

    useEffect(() => {
        fetch('/Text/About.txt')
            .then(response => response.text())
            .then(data => setText(data));
    }, []);

    // const toggleShowMore = () => {
    //     setShowMore(prevState => !prevState);
    // };

    
    return (
        <div id="about" className="about-container">
            <div className="about-header">
                <h1>About Me</h1>
            </div>
            <div className="content">
                <div className="image-container">
                    <img src="/images/IMG_0309-Edit - Copy.jpg" alt="About" />
                </div>
                <button className="show-button" onClick={() => setShowMore(true)}>About <i className="fa-solid fa-angles-right"></i></button>

                <AboutPop trigger={showMore} setTrigger={setShowMore}/>
             
           </div>
        </div>
    );
}

export default About;