import cv2 as cv
import numpy as np
img = cv.imread("гослинг.jpg")

img2 = np.zeros(img.shape, img.dtype)

x1, y1, x2, y2 = 0, 0, 500, 500

img2 = np.zeros([x2 - x1, y2 - y1, img.shape[2]], img.dtype)

for i in range(x1, x2):
    for j in range(y1, y2):
        for k in range(img.shape[2]):
            img2[i - x1, j - y1, k] = img[i, j, k]

cv.namedWindow("1283286754", cv.WINDOW_NORMAL)
cv.imshow("1283286754", img2)
cv.waitKey(0)