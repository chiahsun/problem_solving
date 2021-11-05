
class ParkingSystem {

    var lots: [Int: Int] = [:]
    
    init(_ big: Int, _ medium: Int, _ small: Int) {
        lots[1] = big
        lots[2] = medium
        lots[3] = small
    }
    
    func addCar(_ carType: Int) -> Bool {
        if let cur = lots[carType], 
           cur > 0 {
            lots[carType]! -= 1
            return true
        } else {
            return false
        }
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * let obj = ParkingSystem(big, medium, small)
 * let ret_1: Bool = obj.addCar(carType)
 */