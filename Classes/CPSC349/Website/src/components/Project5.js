import React from 'react';

import { Link } from 'react-router-dom';
import "./Project5.css"

const Project5 = () => {
    return (
        <div className='project-five'>
            <div className="P5header"> <h2>Project 4</h2> </div>
            <Link to="/"> <i className="fa-solid fa-arrow-left-long"></i> Back to Project Gallery</Link>
            <div className="outer-container">
                <div className="image-container"> <img src="/images/project5.png" alt="Project 5 photo" /></div>
                <div className="inner-text-container">
                    <p>This project was part of my Object Oriented Programming course. It demonstrates a deep understanding of OOP by using it to create a simulation of the game Spoons</p>

                    <p>The full project specifications on the README as well as all of the source files are linked below.</p>
                </div>
            </div>
            <a href="https://github.com/gbeelerr/Projects/tree/main/Classes/CPSC231/SpoonsGame" target="_blank" rel="noopener noreferrer"><i className="fab fa-github"></i> Open Project in Github <i className="fab fa-github"></i></a>
        </div>
    );
};

export default Project5;