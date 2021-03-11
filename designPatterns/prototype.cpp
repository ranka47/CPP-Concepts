/* 
    Practised using https://www.youtube.com/watch?v=KBkkEKNlE6I 
    Thanks to CPPNuts
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

using namespace std;

class Bullet {
public:
    string _bulletName;
    float _firePower;
    Bullet (string name, float firePower): _bulletName(name), _firePower(firePower) {
        cout << "Bullet CTOR called" << endl;
    }
    Bullet(const Bullet&) {
        cout << "Bullet Copy CTOR called" << endl;
    }
    virtual ~Bullet() {
        cout << "Bullet DTOR " << _bulletName << " called" << endl;
    };
    virtual unique_ptr<Bullet> clone() = 0;
    void fire(float direction) {
        this->direction = direction;
        cout << "Name: " << _bulletName 
        << "\tFirePower: " << _firePower 
        << "\tDirection: " << this->direction << endl;
    }

private:
    float direction;


};

class SimpleBullet: public Bullet {
public:
    int temp;
    SimpleBullet(string name, float firePower): Bullet(name, firePower), temp(0) {
        cout << "\tSimpleBullet CTOR called" << endl;
    }
    SimpleBullet(const SimpleBullet& obj): Bullet(obj) {
        cout << "\tSimpleBullet Copy CTOR called" << endl;
    }
    ~SimpleBullet() {
        cout << "\tSimpleBullet DTOR called" << endl;
    }
    unique_ptr<Bullet> clone() {
        return make_unique<SimpleBullet>(*this);
    }
};

class GoodBullet: public Bullet {
public:
    GoodBullet(string name, float firePower): Bullet(name, firePower) {
        cout << "\tGoodBullet CTOR called" << endl;
    }
    GoodBullet(const GoodBullet& obj): Bullet(obj) {
        cout << "\tGoodBullet Copy CTOR called" << endl;
    }

    ~GoodBullet() {
        cout << "\tGoodBullet DTOR called" << endl;
    }
    unique_ptr<Bullet> clone() {
        return make_unique<GoodBullet>(*this);
    }

};

enum BulletType {
    SIMPLE, GOOD
};

class BulletFactory {
public:
    unordered_map<BulletType, unique_ptr<Bullet>, hash<int>> prototypes;

    BulletFactory() {
        prototypes[SIMPLE] = make_unique<SimpleBullet>("Simple", 10);
        prototypes[GOOD] = make_unique<GoodBullet>("Good", 20);
    }

    unique_ptr<Bullet> createBullet(BulletType type) {
        // return make_unique<Bullet>(*prototypes[type]);
        return prototypes[type]->clone();
    }

    ~BulletFactory() {
        cout << "BulletFactory DTOR called\n"; 
    }
};

int main() {
    cout << "Contructors will be called twice. One for Simple and one for Good\n";
    BulletFactory bulletFactory;

    cout << "Creating a simple bullet using factory" << endl;
    auto bullet = bulletFactory.createBullet(SIMPLE);
    bullet->fire(90);

    cout << "Creating a good bullet using factory" << endl;
    bullet = bulletFactory.createBullet(GOOD);
    bullet->fire(100);
    bullet->fire(101);

    cout << "Creating a good bullet using factory" << endl;
    bullet = bulletFactory.createBullet(GOOD);
    bullet->fire(100);

    cout << "Creating a simple bullet using factory" << endl;
    bullet = bulletFactory.createBullet(SIMPLE);
    bullet->fire(100);
}