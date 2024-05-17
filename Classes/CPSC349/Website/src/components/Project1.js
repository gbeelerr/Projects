import React, { useEffect, useState } from 'react';

import { Link } from 'react-router-dom';
import "./Project1.css";

const Project1 = () => {
    return (
        <div className='project-one'>
            <div className="P1header"> <h2>Project 1</h2> </div>
            <Link to="/"> <i className="fa-solid fa-arrow-left-long"></i> Back to Project Gallery</Link>
            <div className="outer-container">
                <div className="image-container"> <img src="/images/project1.png" alt="Project 1 photo" /></div>
                <div className="inner-text-container">
                    <p>As mentioned above, this project was started as an asignment in my CPSC 349 - Human Factors class at Chapman University, as part of my final project for the class.</p>

                    <p>The assignment's goal was to build a website that encompassed everything we learned about design and usability for software. It includes the Gestalt Principles: Proximity, Figure/Ground, and Common Fate, and Nielsen's Heuristics: Consistency and Standards, Aesthetic and Minimalist Design, and Help Users Recognize, Diagnose, and Recover from errors. It also is efficient in using Visual Heirarchy, leading users to their goal, and has a colorblind-friendly design.  </p>

                    <p>I created the website using React, which is a component-based Javascript library which makes it easy to create complex UIs with just JS, HTML, and CSS, and the extensive packages that React has.</p>
                </div>
            </div>
            <a href="https://github.com/gbeelerr/Projects/tree/main/Classes/CPSC349/Website" target="_blank" rel="noopener noreferrer"><i className="fab fa-github"></i> Open Project in Github <i className="fab fa-github"></i></a>
        </div>
    );
};

export default Project1;