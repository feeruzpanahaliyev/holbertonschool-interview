#!/usr/bin/python3

'''
Lockboxes algorithm
'''


def canUnlockAll(boxes):
    """
    Returns:
        True if all boxes can be opened, False otherwise.
    """

    accessible_boxes = [0]  # Start with box 0 unlocked
    newly_opened_boxes = accessible_boxes.copy()

    while newly_opened_boxes:
        next_new_boxes = []
        for box_index in newly_opened_boxes:
            for key in boxes[box_index]:
                if key not in accessible_boxes and key < len(boxes):
                    accessible_boxes.append(key)  # Add newly accessible box
                    next_new_boxes.append(key)  # Track for next iteration
        newly_opened_boxes = next_new_boxes[:]

    return len(accessible_boxes) == len(boxes)  # True if all boxes unlocked
