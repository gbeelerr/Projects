import React from 'react';
import './Contact.css';
import SocialBar from './SocialBar';
import ContactForm from './ContactForm';
import * as yup from 'yup';

function Contact() {
    const handleSave = (values) => {
        console.log({values});
    };
    return (
        <div id="contact" className="contact-container">
            <div className="contact-header"> <h1>Contact</h1></div>
            <div className="contact-content">
                <div className="grid-container">
                    <div className="grid-item">
                        <p><i className="fa-solid fa-envelope"></i> Email:</p>
                        <p>beeler@chapman.edu</p>
                        <p>graedonbeeler@icloud.com</p>
                    </div>
                    <div className="grid-item">
                        <p><i className="fa-solid fa-phone"></i> Phone:</p>
                        <p>925-784-5807</p>
                    </div>
                    <div className="grid-item">
                        <p>Socials: </p>
                        <SocialBar />
                    </div>
                </div>
                <ContactForm onSave={handleSave} />
            </div>
        </div>
    );
}

export default Contact;