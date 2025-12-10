/*
 Thank you to professor Dave Matthews for helping with the math

 TODO:
	- flip through shapes
*/

#include <SFML/Graphics.hpp>
#include <vector>
#include <complex>
#include <cmath>
#include "Circle.hpp"
#include "Dot.hpp"

class EpicycleDrawing
{
public:

	struct FourierTerm 
	{
	    int freq;
	    std::complex<double> coeff;
	};

	std::vector<FourierTerm> discreteFourierTransform(const std::vector<std::complex<double>>& signal) 
	{
	    int N = signal.size();
	    std::vector<FourierTerm> terms(N);
	    for (int k = 0; k < N; k++) 
		{
	        std::complex<double> sum(0,0);
	        for (int n = 0; n < N; n++) 
			{
	            double phi = -2 * M_PI * k * n / N;
	
	            sum += signal[n] * std::exp(std::complex<double>(0, phi));
	        }
	        sum /= N;
	        terms[k] = {k, sum};
	    }
	    return terms;
	}

	void run() 
	{
	    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Fourier Drawing");
	    window.setFramerateLimit(60);
	
	    float centerX = 600;
	    float centerY = 400;
	
	    const int N = 500;
	    std::vector<std::complex<double>> signal;
	    for (int i = 0; i < N; i++) 
		{
	        float t = (float)i / N * 2.0f * M_PI;
			
			//parametric equations
			
			//heart
	        //double x = 16 * pow(sin(t), 3) * 20;
	        //double y = -(13*cos(t) - 5*cos(2*t) - 2*cos(3*t) - cos(4*t)) * 20;
			
			//Circle
			//double x = cos(t) * 300;
			//double y = sin(t) * 300;
			
			//Lemniscate
			//double a = 100;
			//double x = a * cos(t) / (1 + sin(t)*sin(t));
			//double y = a * cos(t) * sin(t) / (1 + sin(t)*sin(t));
			
			//square
			//double L = 200; // half side length
			//double x;
			//double y;
			//double segment = fmod(t/(2*M_PI)*4, 1.0); // segment index 0..1
			//if (segment < 0.25) {
			//    x = -L + 8*L*segment; y = -L;
			//} else if (segment < 0.5) {
			//    x = L; y = -L + 8*L*(segment-0.25);
			//} else if (segment < 0.75) {
			//    x = L - 8*L*(segment-0.5); y = L;
			//} else {
			//    x = -L; y = L - 8*L*(segment-0.75);
			//}
			
	
			//rose
			double a = 100;
			double k = 5;
			// radius
			double r = a * cos(k * t);
			double x = r * cos(t);
			double y = r * sin(t);
	
	        signal.push_back({x, y});
	    }
	
	    auto dft = discreteFourierTransform(signal);
	
	    std::vector<sf::Vector2f> path;
	
	    float angle = 0.0f;
	    float dt = 2 * M_PI / N;
	
	    while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
	        while (auto event = window.pollEvent()) 
			{
	            if (event->is<sf::Event::Closed>())
					window.close();
	        }
	
	        window.clear();
	
	        std::complex<double> pos(centerX, centerY);
	        std::complex<double> prevPos = pos;
	
	        for (auto& t : dft) 
			{
	            prevPos = pos;
	            pos += t.coeff * std::exp(std::complex<double>(0, t.freq * angle));
	            Circle c(std::abs(t.coeff), prevPos.real(), prevPos.imag());
	            window.draw(c);
	        }
	
	        Dot tipDot(5, pos.real(), pos.imag());
	        window.draw(tipDot);
	
	        //tip to path
	        path.push_back({(float)pos.real(), (float)pos.imag()});
	
	        if (path.size() > 1) 
			{
	
	            sf::VertexArray pathLine(sf::PrimitiveType::LineStrip, path.size());
	            for (size_t i = 0; i < path.size(); i++) 
				{
	                pathLine[i].position = path[i];
	                pathLine[i].color = sf::Color::Red;
	            }
	            window.draw(pathLine);
	        }
	
	        angle += dt;
	        if (angle > 2*M_PI) 
			{
				angle -= 2*M_PI;
			}
	
	        window.display();
	    }
	}
};

