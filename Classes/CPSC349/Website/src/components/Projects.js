import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import './Projects.css';
import Project1 from './Project1';
import Project2 from './Project2';
import Project3 from './Project3';
import Project4 from './Project4';
import Project5 from './Project5';

const projectsData = [
    {
        id: 1,
        name: 'Project 1',
        imageUrl: '/images/project1.png',
        path: '/project1',
        label: "Digital Portfolio",
        component: Project1,
    },
    {
        id: 2,
        name: 'Project 2',
        imageUrl: '/images/project2.png',
        path: '/project2',
        label: "Super Mario Bros Simulator",
        component: Project2,
    },
    {
        id: 3,
        name: 'Project 3',
        imageUrl: '/images/project3.png',
        path: '/project3',
        label: "Genetic Palindromes Analysis",
        component: Project3,
    },
    {
        id: 4,
        name: 'Project 4',
        imageUrl: '/images/project4.png',
        path: '/project4',
        label: "Student/Faculty Database System",
        component: Project4,
    },
    {
        id: 5,
        name: 'Project 5',
        imageUrl: '/images/project5.png',
        path: '/project5',
        label: "Spoons Simulator",
        component: Project5,
    },
];

function Projects() {
    const navigate = useNavigate();
    const [currentIndex, setCurrentIndex] = useState(0);

    const handleProjectClick = (path) => {
        navigate(path);
    };

    const prevProject = () => {
        setCurrentIndex((prevIndex) => (prevIndex === 0 ? projectsData.length - 1 : prevIndex - 1));
    };

    const nextProject = () => {
        setCurrentIndex((prevIndex) => (prevIndex === projectsData.length - 1 ? 0 : prevIndex + 1));
    };

    return (
        <div id="projects" className="projects-container">
            <h2 style={{ fontSize: '36px', color: '#0097b2' }}>Projects</h2>
            <div className="project-gallery">
                <button onClick={prevProject} className="prev-btn"><i className="fa-solid fa-caret-left"></i></button>
                <div className="projects-grid">
                    {projectsData.map((project) => (
                        <div key={project.id} className="project-container" style={{ transform: `translateX(-${100 * currentIndex}%)` }} onClick={() => handleProjectClick(project.path)}>
                            <div className='project-label'><h4>{project.label}</h4></div>
                            <div className="project-link">
                                <img
                                    src={project.imageUrl}
                                    alt={`Project ${project.id}`}
                                    className="project-image"
                                />
                            </div>
                        </div>
                    ))}
                </div>
                <button onClick={nextProject} className="next-btn"><i className="fa-solid fa-caret-right"></i></button>
            </div>
        </div>
    );
}

export default Projects;