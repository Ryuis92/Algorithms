# https://www.acmicpc.net/problem/2250

import sys
input = sys.stdin.readline

class Problem:
	def __init__(self):
		self.line = int(input())
		self.tree = [[0,0,0] for i in range(self.line)]
		self.numbering = [0 for i in range(self.line)]
		self.curr = 1
		self.root = None

		for i in range(self.line):
			root, left, right = map(int, input().split())
			self.tree[root-1][0] = left
			self.tree[root-1][1] = right
			if left != -1:
				self.tree[left-1][2] = root
			if right != -1:	
				self.tree[right-1][2] = root

		for i in range(len(self.tree)):
			if self.tree[i][2] == 0:
				self.root = i+1
				break	
			
	def inorder(self, root):
		if root == -1:
			return 
		self.inorder(self.tree[root-1][0])
		self.numbering[root-1] = self.curr
		self.curr +=1
		self.inorder(self.tree[root-1][1])
	
	def bfs(self, root):
		q = [root]
		level = 0
		ans = 1
		ans_level = 1
		push_count = 1
		while len(q):
			push_count = len(q)
			left = self.numbering[q[0]-1]
			right = self.numbering[q[0]-1]
			level += 1
			while(push_count):
				push_count -= 1
				p = q.pop(0)
				
				left = min(self.numbering[p-1], left)
				right = max(self.numbering[p-1], right)

				if self.tree[p-1][0] != -1:
					q.append(self.tree[p-1][0])
				if self.tree[p-1][1] != -1:
					q.append(self.tree[p-1][1])
				#print("parent:", p, "left:", left, "right:", right)	
						
			temp = right - left + 1
			if temp > ans:
				ans = temp
				ans_level = level
			
		return ans_level, ans		

	def main(self):
		self.inorder(self.root)
		level, ans = self.bfs(self.root)
		print(level, ans)
		
a = Problem()
a.main()			