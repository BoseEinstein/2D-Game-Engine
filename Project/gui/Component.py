#!/usr/bin/python3
import tkinter as tk

#TODO yeah could really be condensed but at this point...

class Component():

	def __init__(self):
		pass

	def render_component(self):
		pass

	def handle_options(self, e, option, caller):
		option_val = e.get()
		print("{} set {} to {}".format(caller.name, option, option_val))
		#TODO if (option) try: set option on caller
		if option == 'active':
			caller.active = option_val

class Transform_Component(Component):

	def __init__(self):
		pass

	# Using options=[] as default and not doing the check seemingly doesn't work (same w/ other vars)
	def __init__(self, name=None, callback=None, options=None, x_pos=0, y_pos=0, rot=0):
		self.name=name
		self.callback = callback
		self.x_pos = x_pos
		self.y_pos = y_pos
		self.rot = rot
		self.options = {True:[] , False:options}[options==None]
		self.chkbox_vars = []
		self.ge_component = None
		self.active = True

	def set_values(self, x_pos, y_pos, rot):
		self.x_pos = x_pos
		self.y_pos = y_pos
		self.rot = rot
		self.ge_component.setX(x_pos)
		self.ge_component.setY(y_pos)
		self.ge_component.setRotate(rot)

	def render_component(self, root_inspector_frame):
		frame = tk.Frame(root_inspector_frame)
		tk.Label(frame, text="Transform Component", bg="red", fg="white", width=20, borderwidth=2).pack()
		
		assign_transform_entry = tk.Entry(frame)
		entry = ('Position', assign_transform_entry)

		assign_transform_entry.insert(15, "{},{},{}".format(self.x_pos, self.y_pos, self.rot))

		assign_transform_button = tk.Button(frame, text='Assign x,y,rot', command=lambda e=entry: self.callback(e))
		assign_transform_entry.pack()
		assign_transform_button.pack()
		for o in self.options:
			v = tk.IntVar(value=1)
			chk = tk.Checkbutton(frame, text=o, variable=v, command=lambda e=v, opt=o, caller=self: self.handle_options(e, opt, caller))
			chk.pack()
			self.chkbox_vars.append(v)
		frame.pack(fill=tk.X)

class Collider_Component(Component):

	def __init__(self):
		pass

	def __init__(self, name=None, options=None, x_pos=None, y_pos=None, width=None, height=None):
		self.name = name
		self.options = {True:[] , False:options}[options==None]
		self.chkbox_vars = []
		self.ge_component = None
		self.x_pos = x_pos
		self.y_pos = y_pos
		self.width = width
		self.height = height
		self.active = True

	def render_component(self, root_inspector_frame):
		frame = tk.Frame(root_inspector_frame)
		tk.Label(frame, text="Collider Component", bg="red", fg="white", width=20, borderwidth=2).pack()
		for o in self.options:
			v = tk.IntVar(value=1)
			chk = tk.Checkbutton(frame, text=o, variable=v, command=lambda e=v, opt=o, caller=self: self.handle_options(e, opt, caller))
			chk.pack(side=tk.LEFT, anchor=tk.W, expand=tk.YES)
			self.chkbox_vars.append(v)
		frame.pack(fill=tk.X)

class Audio_Component(Component):

	def __init__(self):
		pass

	def __init__(self, name=None, options=None):
		self.name = name
		self.options = {True:[] , False:options}[options==None]
		self.chkbox_vars = []
		self.ge_component = None
		self.active = True

	def render_component(self, root_inspector_frame):
		frame = tk.Frame(root_inspector_frame)
		tk.Label(frame, text="Audio Component", bg="red", fg="white", width=20, borderwidth=2).pack()
		for o in self.options:
			v = tk.IntVar(value=1)
			chk = tk.Checkbutton(frame, text=o, variable=v, command=lambda e=v, opt=o, caller=self: self.handle_options(e, opt, caller))
			chk.pack(side=tk.LEFT, anchor=tk.W, expand=tk.YES)
			self.chkbox_vars.append(v)
		frame.pack(fill=tk.X)

class Image_Component(Component):

	def __init__(self):
		pass

	def __init__(self, name=None, callback=None, file_name=None):
		self.name=name
		self.callback = callback
		self.file_name = file_name
		self.ge_component = None
		self.active = True

	def set_image(self, image):
		self.file_name = image

	def render_component(self, root_inspector_frame):
		frame = tk.Frame(root_inspector_frame)
		tk.Label(frame, text="Image Component", bg="red", fg="white", width=20, borderwidth=2).pack()
		assign_image_entry = tk.Entry(frame)
		entry = ('Position', assign_image_entry)

		if self.file_name:
			assign_image_entry.insert(15, "{}".format(self.file_name))

		assign_image_button = tk.Button(frame, text='Assign image', command=lambda e=entry: self.callback(e))
		assign_image_entry.pack()
		assign_image_button.pack()
		frame.pack(fill=tk.X)

class Text_Component(Component):

	def __init__(self):
		pass

	def __init__(self, name=None, callback=None, text=None):
		self.name=name
		self.callback = callback
		self.text = text
		self.ge_component = None
		self.active = True

	def set_text(self, text):
		self.text = text
		self.ge_component.setText(text)

	def render_component(self, root_inspector_frame):
		frame = tk.Frame(root_inspector_frame)
		tk.Label(frame, text="Text Component", bg="red", fg="white", width=20, borderwidth=2).pack()
		assign_text_entry = tk.Entry(frame)
		entry = ('Position', assign_text_entry)

		if self.text:
			assign_text_entry.insert(15, "{}".format(self.text))

		assign_text_button = tk.Button(frame, text='Assign text', command=lambda e=entry: self.callback(e))
		assign_text_entry.pack()
		assign_text_button.pack()
		frame.pack(fill=tk.X)