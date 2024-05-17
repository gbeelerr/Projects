import React from 'react';

import { Link } from 'react-router-dom';

import "./Project2.css"

const Project2 = () => {
    return (
        <div className='project-two'>
            <div className="P2header"> <h2>Project 2</h2> </div>
            <Link to="/"> <i className="fa-solid fa-arrow-left-long"></i> Back to Project Gallery</Link>
            <div className="outer-container">
                <div className="image-container"> <img src="/images/project2.png" alt="Project 2 photo" /></div>
                <div className="inner-text-container">
                    <p>This project was part of a Data Structures and Algorithms class. The project was exploring pointers in C++ and strictly used primitive array structures.</p>

                    <p>The goal was to make a program on the terminal that simulates a Super Mario game. An input file determines the dimensions of an nxn grid, the number of levels, the number of lives that Mario begins with, and the percentage of the map filled with specific items (empty,mushrooms,coins,goombas,koopas)</p>

                    <p>Mario moves through the levels, collecting coins and mushrooms and fighting koopas and goombas, eventually running out of lives or reaching the boss on the final level. The "game" is won if Mario defeats the boss before he is defeated on his last life. </p>

                    <p>Read the full project description on the Github README</p>
                </div>
            </div>
            <a href="https://github.com/gbeelerr/Projects/tree/main/Classes/CPSC350/PA2" target="_blank" rel="noopener noreferrer"><i className="fab fa-github"></i> Open Project in Github <i className="fab fa-github"></i></a>
        </div>
    );
};

export default Project2;