import {RemoveScrollBar} from 'react-remove-scroll-bar';
import './AboutPop.css';
function AboutPop(props) {

    return (props.trigger) ? (
        <div className="popup">
            <RemoveScrollBar />
            <div className="text-container">
                <div className="text-facts">
                <p><h3>Name:</h3>
                <p>Richard "Graedon" Beeler</p>
                <h3>Age:</h3>
                <p>20</p>
                <h3>School:</h3>
                <p>Chapman University</p>
                <h3>Major:</h3>
                <p>Software Engineering</p>
                </p>
                <h3>Skills:</h3>
                <ul>
                    <li>Data Structures and Algorithms</li>
                    <li>Object Oriented Programming</li>
                    <ul>
                        <li>C++</li>
                        <li>Java</li>
                        <li>Python</li>
                        <li>C#</li>
                    </ul>
                    <li>Data Science/Machine Learning</li>
                    <li>Frontend Development (React)</li>
                    <li>CAD Software</li>
                    <li>Teamwork</li>
                    <li>Problem Solving</li>
                    <li>Communication</li>
                    <li>WSL,Linux/Unix</li>
                    <li>Docker</li>
                    <li>Git</li>
                </ul>
                </div>
                <div className='text-paragraph'>
                <p><h3>Background:</h3>I am currently a Sophomore at Chapman University, planning on graduating in Fall of 2025. I am majoring in Software Engineering and minoring in Economics. Some of my passions include running, working out, watching sports, playing video games, playing guitar and bass, and my faith in Jesus Christ. <br/><br/>I began this portfolio as a project for a Human Factors class which covers effective web design, and decided to create it from scratch using React. I hope to continue adding new projects and updates as I grow as a software developer.</p>
                </div>
                <div className="download-link"> <a href="/public/other/Richard Graedon Beeler Resume 2024 (3).pdf" download="beeler_resume.pdf">Download My Resume</a> </div>
                <button className="close-btn" onClick={() => props.setTrigger(false)}><i className="fa-solid fa-circle-xmark"></i></button>
                {props.children}
            </div>
          
            

        </div>
    ) : "";
}

export default AboutPop