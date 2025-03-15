class ParkingSystem {
private:
    int bigCap;
    int medCap;
    int smallCap;

public:
    ParkingSystem(int big, int medium, int small) {
        bigCap = big;
        medCap = medium;
        smallCap = small;
    }
    
    bool addCar(int carType) {
        if(carType== 1){
            if(bigCap>0){
                bigCap--;
                return true;
            }else{
                return false;
            }
        }
        else if(carType==2){
            if(medCap>0){
                medCap--;
                return true;
            }else{
                return false;
            }
        }else{
            if(smallCap > 0){
                smallCap--;
                return true;
            }else{
                return false;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */