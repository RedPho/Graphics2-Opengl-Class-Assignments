def scale(values, min, max):
    scaled_values = []
    for index, x in enumerate(values):
        x_new = ((x - values[0]) / (values[-1] - values[0])) * (max - min) + min
        scaled_values.append(x_new)
    return scaled_values


old_values = [1,2,5,8,9,10]
print("Old values: ", old_values)
print("Scaled (-1.0, 1.0): ", scale(old_values, -1.0, 1.0))
print("Scaled (0.0, 1.0): ", scale(old_values, 0.0, 1.0))
print("Scaled (0.0, 100.0): ", scale(old_values, 0.0, 100.0))
print("Scaled (10.0, 15.0): ", scale(old_values, -5.0, 15.0))

print("Old values: ", old_values)
print("Scaled (-1.0, 1.0): ", [f"{x:.2f}" for x in scale(old_values, -1.0, 1.0)])
print("Scaled (0.0, 1.0): ", [f"{x:.2f}" for x in scale(old_values, 0.0, 1.0)])
print("Scaled (0.0, 100.0): ", [f"{x:.2f}" for x in scale(old_values, 0.0, 100.0)])
print("Scaled (10.0, 15.0): ", [f"{x:.2f}" for x in scale(old_values, 10.0, 15.0)])