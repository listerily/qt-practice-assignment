import os
from PIL import Image

# Fill these variable before running this tool
image_path = r"./crops.png"
image_id = 7
image = Image.open(image_path)

os.mkdir(r'./output_images')
if image.width % 16 != 0 or image.height % 16 != 0:
    print('Error: image could not be cropped to 16x16 files exactly.')

for i in range(0, image.width // 16):
    for j in range(0, image.height // 16):
        cropped_image = image.crop((i * 16, j * 16, i * 16 + 16, j * 16 + 16))
        all_blank = True
        for x in range(0, 16):
            for y in range(0, 16):
                if cropped_image.load()[x, y] != (0, 0, 0, 0):
                    all_blank = False
        # Only blocks with images could be saved into files.
        if not all_blank:
            cropped_image.save(open(r'./output_images/' + str(image_id) + '_' + str(i) + '_' + str(j) + '.png', 'wb'))

pixels = image.load()
for i in range(0, image.width // 16):
    for j in range(0, image.height // 16):
        # Draw this block
        for x in range(0, 16):
            pixels[i * 16 + 15, j * 16 + x] = (255, 255, 255, 255)
            pixels[i * 16 + x, j * 16 + 15] = (255, 255, 255, 255)
            # Draw number for this block
image.save(open(r'proc_crops_tiles.png', 'wb'))
