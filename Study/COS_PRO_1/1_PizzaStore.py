class DeliveryStore():
  def set_oreder_list(self, order_list):
    pass
  def get_total_price(self):
    pass

class Food:
  def __init__(self, name, price):
    self.name = name
    self.price = price

class PizzaStore:
  def __init__(self):
    menu_names = ['Cheese', 'Potato', 'Shrimp', 'Pineapple', 'Meatball']
    menu_prices = [11100, 12600, 13300, 21000, 19500]
    self.menu_list = list()
    for i in range(min(len(menu_names),len(menu_prices))):
      self.menu_list.append(Food(menu_names[i],menu_prices[i]))
    self.order_list = list()

  def @@@:
    for order in order_list:
      self.order_list.append(order)

  def @@@:
    total_price = 0
    for order in self.order_list:
      for menu in self.menu_list:
        if order == menu.name:
          total_price += menu.price
    return total_price

def solution(order_list):
  delivery_store = PizzaStore()
  delivery_store.set_order_list(order_list)
  total_price = delivery_store.get_total_price()
  return total_price

order_list = ['Cheese', 'Pineapple', 'Meatball']
ret = solution(order_list)

print(ret)
