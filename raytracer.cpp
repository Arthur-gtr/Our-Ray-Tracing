#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include <cmath>
#include <algorithm> 

struct Vec3 {
    float x, y, z;
    Vec3(float x_=0.f, float y_=0.f, float z_=0.f) : x(x_), y(y_), z(z_) {}

    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }


    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator*(float s) const { return Vec3(x*s, y*s, z*s); }
    Vec3 operator/(float s) const { return Vec3(x/s, y/s, z/s); }
};

float dot(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float norm(const Vec3& v) {
    return std::sqrt(dot(v, v));
}

Vec3 normalize(const Vec3& v) {
    const float EPS = 1e-8f;
    float n = norm(v);
    if (n < EPS) return Vec3(0.f, 0.f, 0.f);
    return v / n;
}

float intersection(const Vec3& u, const Vec3& OC, float r) {
    float a = 1.0f;
    float b = -2.0f * dot(u, OC);
    float c = norm(OC) * norm(OC) - r * r;

    float delta = b * b - 4.0f * a * c;

    if (delta == 0.0f) {
        return std::max(-b / (2.0f * a), 0.0f);
    } 
    else if (delta > 0.0f) {
        float x1 = (-b - std::sqrt(delta)) / (2.0f * a);
        float x2 = (-b + std::sqrt(delta)) / (2.0f * a);

        if (std::min(x1, x2) >= 0.0f)
            return std::min(x1, x2);
        else
            return std::max(0.0f, std::max(x1, x2));
    } 
    else {
        return 0.0f;
    }
}

#define D 2000
Vec3 direction(int x, int y){
    return Vec3(x - 1920 / 2, y - 1080 / 2, D);
}

Vec3 speculaire(const Vec3& u, const Vec3& n, const Vec3& l, float alpha)
{
    float ln = dot(l, n);
    Vec3 couleur_lumiere(255, 0, 0);
    
    if (alpha < 1)
        alpha = 1;
    if (ln > 0.0f) {
        Vec3 r = normalize(u - n * (2.0f * dot(n, u)));
        float spec = std::pow(std::max(dot(l, r), 0.0f), alpha);
        return couleur_lumiere * spec;
    } else {
        return Vec3(0.0f, 0.0f, 0.0f);
    }
}


void fill_color(sf::Color color, unsigned int x, unsigned int y, std::vector<sf::Uint8>& buffer, const unsigned int width, const unsigned int height, Vec3 color_)
{
    int actual_pixel = (y * width + x) * 4;

    buffer[actual_pixel] = color_.x;
    buffer[actual_pixel + 1] = color_.y;
    buffer[actual_pixel + 2] = color_.z;
    buffer[actual_pixel + 3] = 255;
}

void fill_buffer(const unsigned int width, const unsigned int height, std::vector<sf::Uint8>& buffer, Vec3 centre, float rayon, sf::Color couleur){
    Vec3 u;
    Vec3 lumiere(-20 , -25, -15);
    float inter;
    Vec3 OM;
    Vec3 ML;
    Vec3 color;
    Vec3 new_couleur(couleur.r, couleur.g, couleur.b);
    float tmp;
    Vec3 spec;

    for(unsigned int x = 0; x < width; x++)
        for(unsigned int y = 0; y < height; y++){
            u = normalize(direction(x, y));
            inter = intersection(u, centre, rayon);
            if (inter != 0){
                OM = u*inter;
                ML = lumiere-OM;
                Vec3 l  = normalize(ML);
                Vec3 n  = normalize(OM - centre);
                spec = speculaire(u, n , l, 50.f);
                color = spec+(new_couleur*std::max(dot(n, l), 0.0f));
                if (color.x > 255) color.x = 255;
                if (color.y > 255) color.y = 255;
                if (color.z > 255) color.z = 255;
                if (color.x < 0) color.x = 0;
                if (color.y < 0) color.y = 0;
                if (color.z < 0) color.z = 0;
                fill_color(sf::Color(58, 84, 216), x, y, buffer, width, height, color);
            }
        }
    }


int main() {
    const unsigned int width = 1920;
    const unsigned int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer Buffer");
    std::vector<sf::Uint8> buffer(width * height * 4, 100);

    sf::Vector3f Origine(0, 0 ,0);
    double distance_origine_object = 0.0f;

    sf::Vector2f P(0, 0);

    Vec3 centre(0, 0, 10);
    float rayon = 1;
    sf::Color couleur(58, 84, 216);

    fill_buffer(width, height, buffer, centre, rayon, couleur);
    std::cout << "Fill end\n";

    sf::Image image;
    image.create(width, height, buffer.data());

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}