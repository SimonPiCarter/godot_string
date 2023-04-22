extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready():
	$Test.set_test([])
	var test = $Test.get_test()


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
