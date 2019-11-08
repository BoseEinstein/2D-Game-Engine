#!/usr/bin/python3
import tkinter as tk
import ge
import random
from Component import *
from PIL import ImageTk,Image

class GameObject():

	# Using components=[] as default and not doing the check seemingly doesn't work
	def __init__(self, name=None, components=None):
		self.gid = random.randint(1000, 9999)
		self.ge_gameObject = ge.GameObject(self.gid)
		self.ge_components = []
		self.name = name
		self.components = {True:[] , False:components}[components==None]
		self.option = 'active'
		# ge.addObject(self.ge_gameObject)
	
	def handle_options(self, e):
		print("{} set {} to {}".format(self.name, self.option, e.get()))

	def create_label_frame(self, gameobjects_frame_root, callback):
		frame = tk.Frame(gameobjects_frame_root)
		label = tk.Label(frame, text=self.name, bg='black', fg='white', width=20, relief='sunken', borderwidth=2)
		label.bind("<Button-1>", callback)
		label.pack(fill=tk.X)

		active_chkbox_var = tk.IntVar(value=1)
		chk = tk.Checkbutton(frame, text=self.option, variable=active_chkbox_var, command=lambda e=active_chkbox_var: self.handle_options(e))
		chk.pack(side=tk.LEFT, anchor=tk.W, expand=tk.YES)
		return frame

	def create_inspector_frame(self, inspector_frame_root):
		inspector_frame = tk.Frame(inspector_frame_root, bg='black', relief='sunken', borderwidth=2)
		tk.Label(inspector_frame, text='Selected: {}'.format(self.name), bg='black', fg='white', width=20, relief='sunken', borderwidth=2).pack(fill=tk.X)
		for comp in self.components:
			comp.render_component(inspector_frame)
		return inspector_frame

	# Can only add 1 of each type of component
	def add_component(self, component_name, callback=None):
		if self.is_component_already_attached(component_name):
			print("Component already attached")
			return
		if component_name == 'transform':
			transform_component = Transform_Component('transform', callback, ['active'])
			ge_transform = self.ge_gameObject.Transform(self.gid)
			transform_component.ge_component = ge_transform
			self.components.append(transform_component)
			self.ge_components.append(ge_transform)
		elif component_name == 'collider':
			collider_component = Collider_Component('collider', ['collide'])
			ge_collider = self.ge_gameObject.Collider(self.gid)
			collider_component.ge_component = ge_collider
			self.components.append(collider_component)
			self.ge_components.append(ge_collider)
		elif component_name == 'audio':
			audio_component = Audio_Component('audio', ['play'])
			ge_audio = self.ge_gameObject.AudioManager(self.gid)
			audio_component.ge_component = ge_audio
			self.components.append(audio_component)
			self.ge_components.append(ge_audio)
		elif component_name == 'text':
			text_component = Text_Component('text', callback)
			ge_text = self.ge_gameObject.TextComponent(self.gid)
			text_component.ge_component = ge_text
			self.components.append(text_component)
			self.ge_components.append(ge_text)
		elif component_name == 'image':
			image_component = Image_Component('image', callback)
			ge_image = self.ge_gameObject.ImageComponent(self.gid)
			image_component.ge_component = ge_image
			self.components.append(image_component)
			self.ge_components.append(ge_image)
		else:
			pass
		return

	def render_image(self, canvas, images):
		image_component = [x for x in self.components if isinstance(x, Image_Component)]
		if not len(image_component): return
		image_component = image_component[0]
		try:
			img = Image.open(image_component.file_name)

			transform_component = [x for x in self.components if isinstance(x, Transform_Component)][0]
			print("Creating image\n")
			rot_img = ImageTk.PhotoImage(img.rotate(transform_component.rot))
			return (rot_img, transform_component.x_pos, transform_component.y_pos)
		except:
			print("Unable to load file {}").format(image_component.file_name)
			return None



	def is_component_already_attached(self, component_name):
		component = [x for x in self.components if x.name == component_name]
		return len(component) == 1

	def get_component(self, component_name):
		component = [x for x in self.components if x.name == component_name]
		if len(component):
			return component[0]
		else:
			return None