import cv2 as cv
import numpy as np
img = cv.imread("ohhh.jpg")

img2 = np.zeros(img.shape, img.dtype)

for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        for k in range(img.shape[2]):
            img2[i, j, k] = min(img[i, j, k] * 2 + 10, 255)

cv.namedWindow("1283286754", cv.WINDOW_NORMAL)
cv.imshow("1283286754", img2)
cv.waitKey(0)