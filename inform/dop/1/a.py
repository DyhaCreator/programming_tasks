import cv2 as cv
import numpy as np
img = cv.imread("гослинг.jpg")

img2 = np.zeros(img.shape, img.dtype)

x1, y1, x2, y2 = 100, 100, 400, 400

#img2 = np.zeros([x2 - x1, y2 - y1, img.shape[2]], img.dtype)

for i in range(x1, x2):
    for j in range(y1, y2):
        buff = img[i, j, 0]
        img[i, j, 0] = img[i, j, 1]
        img[i, j, 1] = img[i, j, 2]
        img[i, j, 2] = buff

cv.rectangle(img, (x1, y1), (x2, y2), (0, 255, 255), 10)

for i in range(x1, x2):
    for j in range(y1, y2):
        for k in range(img.shape[2]):
            img2[i, j, k] = 0

cv.namedWindow("1283286754", cv.WINDOW_NORMAL)
cv.imshow("1283286754", img)
cv.waitKey(0)