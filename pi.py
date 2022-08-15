import random

from numpy import square

def getPi(numOfRuns=1000):
    #assuming a square with circle inscribed in it. square side length = 2*radius of circle and both centered at origin
    radius = 1
    circleAreaCount = 0
    squareAreaCount = 0
    for i in range(numOfRuns):
        # getting random x and y values between +/- radius 
        currentX = random.random()*(2*radius) - radius
        # print(currentX)
        currentY = random.random()*(2*radius) - radius
        # print(currentY)
        squareAreaCount += 1
        if (currentY**2 + currentX**2) <= (radius**2):
            circleAreaCount += 1

    res_pi = 4*circleAreaCount/squareAreaCount
    print("pi is", res_pi)
    # print(squareAreaCount)
    # print(circleAreaCount)

if __name__ == "__main__":
    getPi(10000000)