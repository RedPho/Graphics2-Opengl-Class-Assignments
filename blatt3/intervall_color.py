from PIL import Image, ImageDraw

# Load the scalar field image
image_path = "task-intervall_use.png"  # Update the path if necessary
img = Image.open(image_path)
draw = ImageDraw.Draw(img)

# Example scalar values after rescaling (this would come from your scaling step)
# Assuming you have a 2D list or array of values corresponding to the scalar field grid.
# Here is an example placeholder
rescaled_values = [
    [1, 1, 1, 10, 10],  # Row 1 (placeholder)
    [1, 10, 9, 8, 1],   # Row 2 (placeholder)
    [1, 2, 9, 10, 1]    # Row 3 (placeholder)
    # Add the rest of the grid values here
]

# Define your color mapping (example)
# Replace these with the actual RGB values that correspond to the scalar values
color_map = {
    1: (255, 255, 255),   # White for 1
    10: (0, 0, 0),        # Black for 10
    9: (128, 128, 128),   # Gray for 9
    8: (255, 0, 0),       # Red for 8
    2: (0, 255, 0)        # Green for 2
}

# Assuming you know the dimensions of each cell in the image grid
# For example, if each cell is 50x50 pixels
cell_width, cell_height = 50, 50

# Loop over the grid to color each cell
for row_idx, row in enumerate(rescaled_values):
    for col_idx, value in enumerate(row):
        # Get the top-left corner of the cell
        top_left_x = col_idx * cell_width
        top_left_y = row_idx * cell_height
        bottom_right_x = top_left_x + cell_width
        bottom_right_y = top_left_y + cell_height
        
        # Get the color corresponding to the scalar value
        color = color_map.get(value, (0, 0, 0))  # Default to black if value not in color_map
        
        # Draw the rectangle for the cell
        draw.rectangle([top_left_x, top_left_y, bottom_right_x, bottom_right_y], fill=color)

# Save the colored image
output_path = "colored_scalarfield.png"
img.save(output_path)
print(f"Image saved to {output_path}")
