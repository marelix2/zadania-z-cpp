#include <iostream>
#include <string>
#include <sstream>
class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_ob_seats);
    bool canceReservations(int number_ob_seats);
    void setReserved(int);
private:
    int id_;
    int capacity_;
    int reserved_;
    double setPrnct(int ,int);
};
void FlightBooking::printStatus()
{
    std::cout<<"Flight "<< id_ <<": ["<<reserved_<<"]/["<<capacity_<<"] (["<<setPrnct(capacity_,reserved_)<<"]%) seats taken"<<std::endl;
    
    // print report here
}

void FlightBooking::setReserved(int a){
    
    reserved_ += a;
    
}

double FlightBooking::setPrnct(int capacity, int reserved){
    
    return ((double)reserved/capacity)* 100.0;
    
    
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    id_ = id;
    capacity_ = capacity;
    if(reserved < 0)  reserved = 0;
    
    if(((double)reserved/capacity)* 100.0 <= 105.0) reserved_ = reserved;
    else reserved_ = 0;
    
    
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
    if(setPrnct(capacity_,reserved_ + number_ob_seats) <= 105.0 ) return true;
    else
        return false;
}
bool FlightBooking::canceReservations(int number_ob_seats)
{
    
    if(reserved_ > number_ob_seats && reserved_ <= 0) return true;
    
    return false;
}
int main() {
    int reserved = 0,
            capacity = 0;
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;
    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;
    FlightBooking booking(1, capacity, reserved);
    std::string command = "";
    std::cin.ignore();
    while (command != "quit")
    {
        booking.printStatus();
        std::cout << "What would you like to do?: ";
        getline(std::cin,command);
        
        if(command.substr(1,3).compare("add")){
            
            std::string tmp = command.substr(4);
            std::istringstream iss(tmp);
            int a;
            iss >> a;
            
            if(booking.reserveSeats(a)) booking.setReserved(a);
        }else if(command.substr(1,6).compare("cancel")){
            
            std::string tmp = command.substr(7);
            std::istringstream iss(tmp);
            int a;
            iss >> a;
            
            if(booking.canceReservations(a)) booking.setReserved(-a);
        }
        else std::cout<< "Cannot perform this operation"<<std::endl;
        
        
        
        
        
    }
    return 0;
}

