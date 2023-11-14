# import pygame
# import random

# # Define some colors
# BLACK = (  0,   0,   0)
# WHITE = (255, 255, 255)
# RED   = (255,   0,   0)
# GREEN = (0, 255, 0)
# BLUE = (0, 0, 255)

# class Block(pygame.sprite.Sprite):
#   def __init__(self, color, width, height):
#     super().__init__()
#     self.image = pygame.Surface([width, height])
#     self.image.fill(color)
#     self.rect = self.image.get_rect()
#     pygame.draw.ellipse(self.image, color, [0, 0, width, height])
  

  

# # Initialize Pygame
# pygame.init()

# # Set the height and width of the screen
# screen_width = 700
# screen_height = 400
# screen = pygame.display.set_mode([screen_width, screen_height])


# block_list = pygame.sprite.Group()
# all_sprites_list = pygame.sprite.Group()

# for i in range(15):
#   player = Block(RED, 20, 15)
#   player.rect.x = (screen_width/5)*(i%5+1)-10
#   player.rect.y = (screen_height/6)*(i//5+1)
#   all_sprites_list.add(player)

# for i in range(3):
#   block = Block(GREEN, 20, 15)
#   block.rect.x = (screen_width/4)*(i+1)-10
#   block.rect.y = screen_height*4/6
#   all_sprites_list.add(block)

# blueBlock = Block(BLUE, 20, 15)
# blueBlock.rect.x = (screen_width/2-10)
# blueBlock.rect.y = screen_height*5/6
# all_sprites_list.add(blueBlock)


# done = False

# clock = pygame.time.Clock()


# while not done:
#     for event in pygame.event.get():
#         if event.type == pygame.QUIT:
#             done = True

#     # Clear the screen
#     screen.fill(WHITE)
#     all_sprites_list.draw(screen)

#     clock.tick(60)
#     pygame.display.flip()