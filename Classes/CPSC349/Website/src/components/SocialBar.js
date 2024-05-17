import React from 'react';
import './SocialBar.css';
import '@fortawesome/fontawesome-free/css/all.min.css';

function SocialBar() {
    return (
        <div className="social-bar">
            <a href="https://www.linkedin.com/in/graedon-beeler-a81281292/" target="_blank" rel="noopener noreferrer"><i className="fab fa-linkedin"></i></a>
            <a href="https://github.com/gbeelerr" target="_blank" rel="noopener noreferrer"><i className="fab fa-github"></i></a>
            <a href="https://www.instagram.com/graedon_beeler04/" target="_blank" rel="noopener noreferrer"><i className="fab fa-instagram"></i></a>
            {/* Add more social media links and icons as needed */}
        </div>
    );
}

export default SocialBar;