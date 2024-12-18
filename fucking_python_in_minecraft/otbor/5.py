import minecraft as mine
mc = mine.Minecraft.create()

mc.setBlock(0, 0, 0, 1)
mc.setBlock(0, 1, 0, 1)
mc.setBlock(0, 2, 0, 1)
mc.setBlock(1, 2, 0, 1)
mc.setBlock(-1, 2, 0, 1)
mc.setBlock(0, 2, 1, 1)
mc.setBlock(0, 2, -1, 1)
