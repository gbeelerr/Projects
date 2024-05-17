import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import './App.css';
import Header from './components/Header';
import About from './components/About';
import Projects from './components/Projects';
import Contact from './components/Contact';
import Footer from './components/Footer';
import Project1 from './components/Project1';
import Project2 from './components/Project2';
import Project3 from './components/Project3';
import Project4 from './components/Project4';
import Project5 from './components/Project5';

function App() {
  return (
    <div className="App">
      <Header />
      <div className="main-content">
        <About />
        <Router>
          <Routes>
            <Route path="/" element={<Projects />} />
            <Route path="/project1" element={<Project1 />} />
            <Route path="/project2" element={<Project2 />} />
            <Route path="/project3" element={<Project3 />} />
            <Route path="/project4" element={<Project4 />} />
            <Route path="/project5" element={<Project5 />} />

          </Routes>
        </Router>
        <Contact />
        </div>
        <Footer />
      </div>
      );
}

      export default App;