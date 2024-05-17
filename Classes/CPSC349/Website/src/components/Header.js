import React from 'react';
import { Link } from 'react-scroll';
import './Header.css';

function Header() {
    return (
        <header className="header">
            <div className="logo">
                <a href="#">
               {/* <img src="/images/Richard Graedio.png" alt="Logo" className="logo-style"/>*/}
                <img src="/images/Logo maker project.png" alt="Logo" className="logo-style" />
                </a>
            </div>
            <nav className="navigation">
               {/* <button className="nav-button">Home</button>*/}
                <Link to="about" smooth={true} duration={500} className="nav-link">About</Link>
                <Link to="projects" smooth={true} duration={500} className="nav-link">Projects</Link>
                <Link to="contact" smooth={true} duration={500} className="nav-link">Contact</Link>
            </nav>
            <div className="home">
                <a href="#" className="home-icon">
            <i className="fas fa-home"></i>
                </a>
            </div>
        </header>
    );
}

export default Header;
