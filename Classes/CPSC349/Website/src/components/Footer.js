import React from 'react';
import './Footer.css';
import SocialBar from './SocialBar';
import { Link } from 'react-scroll';
function Footer() {
    return (
        <footer className="footer">
            <div className="footer-content">
                <div className="left-section">
                    <div>
                        <p><strong>Richard Graedon Beeler</strong></p>
                        <p>925-784-5807</p>
                        <p>beeler@chapman.edu</p>
                    </div>
                    <div>
                        <SocialBar />
                    </div>
                </div> {/**/}
              <nav className="footer-nav"> 
                   {/* <a href="#">Home</a> */}
                    <a href="/" className="nav-link"><i className="fas fa-home"></i></a>
                    <Link to="about" smooth={true} duration={500} className="nav-link">About</Link>
                    <Link to="projects" smooth={true} duration={500} className="nav-link">Projects</Link>
                    <Link to="contact" smooth={true} duration={500} className="nav-link">Contact</Link>

                   
                </nav> {/**/}

            </div>
        </footer>
    );
}

export default Footer;