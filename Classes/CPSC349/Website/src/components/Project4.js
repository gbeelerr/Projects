import React from 'react';

import { Link } from 'react-router-dom';

import "./Project4.css"

const Project4 = () => {
    return (
        <div className='project-four'>
            <div className="P4header"> <h2>Project 4</h2> </div>
            <Link to="/"> <i className="fa-solid fa-arrow-left-long"></i> Back to Project Gallery</Link>
            <div className="outer-container">
                <div className="image-container"> <img src="/images/project4.png" alt="Project 4 photo" /></div>
                <div className="inner-text-container">
                    <p>This project was an assigment in my Data Structures and Algorithms course. It uses Lazily-Balanced Binary Sort Trees as well as other data structures to create a Student/Faculty database system</p>

                    <p>The options that the user is given (until exit) are the following: <br />
                        <br />1.	Print all students and their information (sorted by ascending id #)
                        <br /> 2.	Print all faculty and their information (sorted by ascending id #)
                        <br />3.	Find and display student information given the student id
                       <br /> 4.	Find and display faculty information given the faculty id
                        <br />5.	Add a new student
                        <br />6.	Delete a student given the id
                       <br /> 7.	Add a new faculty member
                       <br /> 8.	Delete a faculty member given the id.
                       <br /> 9.	Change a student’s advisor given the student id and the new faculty id.
                        <br />10.	Remove an advisee from a faculty member given the ids
                        <br />11.	Exit
                    </p>

                    <p>More information can be found on the project's README, linked below</p>


                </div>
            </div>
            <a href="https://github.com/gbeelerr/Projects/tree/main/Classes/CPSC350/PA5" target="_blank" rel="noopener noreferrer"><i className="fab fa-github"></i> Open Project in Github <i className="fab fa-github"></i></a>
        </div>
    );
};

export default Project4;