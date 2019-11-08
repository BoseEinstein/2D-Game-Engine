#!/usr/bin/python3
import tkinter as tk

class Tile():

	def __init__(self, x_pos, y_pos):
		self.x_pos = x_pos
		self.y_pos = y_pos
		self.frame = None
		self.name = "{},{}".format(x_pos, y_pos)
		#TODO add attributes

	def render_tile(self, world_view_frame_root, callback):
		self.frame = tk.Frame(world_view_frame_root, bg='#FFF', width=50, height=50, relief='sunken', borderwidth=2, name=self.name)
		self.frame.grid(row=self.x_pos, column=self.y_pos, sticky=tk.NE)
		self.frame.bind("<Button-1>", callback)

	def create_inspector_frame(self, inspector_frame_root):
		inspector_frame = tk.Frame(inspector_frame_root, bg='white', relief='sunken', borderwidth=2)
		tk.Label(inspector_frame, text="Selected: {}".format(self.name), bg="white", fg="black", width=20, borderwidth=2).pack()
		#TODO add attributes
		return inspector_frame