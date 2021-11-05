
class ParkingSystem {

    var big, medium, small: Int
    
    init(_ big: Int, _ medium: Int, _ small: Int) {
        self.big = big
        self.medium = medium
        self.small = small
    }
    
    func addCar(_ carType: Int) -> Bool {
        var res: Int = 0
        switch carType {
            case 1: 
                big -= 1 
                res = big
            case 2: 
                medium -= 1 
                res = medium
            case 3:
                small -= 1
                res = small
            default:
                break
        }
        return (res >= 0)
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * let obj = ParkingSystem(big, medium, small)
 * let ret_1: Bool = obj.addCar(carType)
 */