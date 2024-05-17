import React from 'react';

import { Link } from 'react-router-dom';

import "./Project3.css"

const Project3 = () => {
    return (
        <div className='project-three'>
            <div className="P3header"> <h2>Project 3</h2> </div>
            <Link to="/"> <i className="fa-solid fa-arrow-left-long"></i> Back to Project Gallery</Link>
            <div className="outer-container">
                <div className="image-container"> <img src="/images/project3.png" alt="Project 3 photo" /></div>
                <div className="inner-text-container">
                    <p>This project, "Genetic Palindromes" was part of my Data Structures and Algorithms class. The purpose was to demonstrate use of doubly linked lists.</p>

                    <p>The project takes in DNA sequences from a specified file, and for each, determines whether the sequence is a genetic palindrome (defined in the GitHub README), and whether any substrings of the sequence are genetic palindromes, printing them out to the terminal in order of length.</p>

                    <p>The full project specifications are listed in the README in the attatched GitHub link below.</p>
                </div>
            </div>
            <a href="https://github.com/gbeelerr/Projects/tree/main/Classes/CPSC350/PA4" target="_blank" rel="noopener noreferrer"><i className="fab fa-github"></i> Open Project in Github <i className="fab fa-github"></i></a>
        </div>
    );
};


export default Project3;