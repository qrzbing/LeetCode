from typing import List


class Solution:

    def findOneRecipe(self, recipe: str, ingredient: List[str]) -> bool:
        for food in ingredient:
            if food in self.supplies:
                continue
            else:
                if food in self.recipes:
                    if food in self.finding:
                        return False
                    self.finding.append(food)
                    if self.findOneRecipe(food, self.ingredients[self.recipes.index(food)]) is True:
                        continue
                    else:
                        return False
                return False
        self.supplies.append(recipe)
        return True

    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        self.recipes = recipes
        self.ingredients = ingredients
        self.supplies = supplies
        self.finding = []
        ret = []
        for i in range(0, len(recipes)):
            if self.findOneRecipe(recipes[i], ingredients[i]) is True:
                self.supplies.append(recipes[i])
                ret.append(recipes[i])
        return ret


sol = Solution()
print(sol.findAllRecipes(["bread"], [
      ["yeast", "flour"]], ["yeast", "flour", "corn"]))
print(sol.findAllRecipes(["ju", "fzjnm", "x", "e", "zpmcz", "h", "q"],
                         [["d"], ["hveml", "f", "cpivl"], ["cpivl", "zpmcz", "h", "e", "fzjnm", "ju"],
                          ["cpivl", "hveml", "zpmcz", "ju", "h"], ["h", "fzjnm", "e", "q", "x"], ["d", "hveml", "cpivl", "q", "zpmcz", "ju", "e", "x"], ["f", "hveml", "cpivl"]], ["f", "hveml", "cpivl", "d"]))
