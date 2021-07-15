import math
import random
import json

# Generator Tool 1:

# output = ""
# for x in range(0,32):
#     for y in range(0,32):
#         rand = random.randint(0,21)
#         aux = 0
#         if rand == 0:
#             aux = 0
#         elif 2 <= rand <= 10:
#             aux = 1
#         elif 10 <= rand <= 18:
#             aux = 5
#         elif rand == 19:
#             aux = 26
#         elif rand == 20:
#             aux = 22
#         output += ",{\"id\":\"grass_" + str(aux) + "\",\"pos\":[" + str(x) + "," + str(y) + "]}"
#
# print(output)

# Generator Tool 2:

# for item in input:
#     if item["id"].startswith("grass_"):
#         pos = item["pos"]
#         if pos[1] >= 16:
#             rand = random.randint(0,24)
#             if rand <= 4:
#                 item["id"] = "grass_14"
#             elif rand <= 9:
#                 item["id"] = "grass_6"
#             elif rand <= 14:
#                 item["id"] = "grass_8"
#             elif rand <= 18:
#                 item["id"] = "grass_12"
#             elif rand == 19:
#                 item["id"] = "grass_27"
#             elif rand == 20:
#                 item["id"] = "grass_28"
#             elif rand == 21:
#                 item["id"] = "grass_29"
#             elif rand == 22:
#                 item["id"] = "grass_30"
#             else:
#                 item["id"] = "grass_31"
#
# print(input)

answer = ""
for x in range(-16, 48):
    for y in range(-16, 48):
        if x < -1 or y < -1 or x > 32 or y > 32:
            rand = random.randint(0,6)
            if rand == 0:
                answer += ",{\"id\":\"border_9\",\"pos\":[" + str(x) + "," + str(y) + "]}"
            elif rand == 1:
                answer += ",{\"id\":\"border_10\",\"pos\":[" + str(x) + "," + str(y) + "]}"
            else:
                answer += ",{\"id\":\"border_8\",\"pos\":[" + str(x) + "," + str(y) + "]}"

        elif x == -1 and y == -1:
            answer += ",{\"id\":\"border_0\",\"pos\":[" + str(x) + "," + str(y) + "]}"
        elif x == 31 and y == -1:
            answer += ",{\"id\":\"border_2\",\"pos\":[" + str(x) + "," + str(y) + "]}"
        elif x == 31 and y == 31:
            answer += ",{\"id\":\"border_4\",\"pos\":[" + str(x) + "," + str(y) + "]}"
        elif x == -1 and y == 31:
            answer += ",{\"id\":\"border_6\",\"pos\":[" + str(x) + "," + str(y) + "]}"
        elif x == -1 and ((y % 2) + 2) % 2 == 1:
            answer += ",{\"id\":\"border_7\",\"pos\":[" + str(x) + "," + str(y) + "]}"
        elif x == 31 and ((y % 2) + 2) % 2 == 1:
            answer += ",{\"id\":\"border_3\",\"pos\":[" + str(x) + "," + str(y) + "]}"
        elif y == -1 and ((x % 2) + 2) % 2 == 1:
            answer += ",{\"id\":\"border_1\",\"pos\":[" + str(x) + "," + str(y) + "]}"
        elif y == 31 and ((x % 2) + 2) % 2 == 1:
            answer += ",{\"id\":\"border_5\",\"pos\":[" + str(x) + "," + str(y) + "]}"
print(answer)
