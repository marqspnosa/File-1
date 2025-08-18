from djitellopy import tello
import time

def basic_controls(drone):

    #connect to the drone
    drone.connect()
    print(f"Battery: {tello.get_battery()}%")

    #control the drone to move up, down, left, right
    drone.move(100)

    # drone takeoff
    drone.takeoff()

    # drone rotation
    drone.rotate_clockwise(360)
 
    # drone lands
    drone.land()

    # end tello 
    drone.end()

    def main():
        
        drone = tello.Tello()
        basic_controls(drone)


if __name__ == "__main__":
    main()
