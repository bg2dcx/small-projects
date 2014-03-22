#!/usr/bin/python
import sys
import os
import re
import copy
#import networkx as nx
#import matplotlib.pyplot as plt

#atom = value[]



def atom_intersection(atom1,atom2):
	ans = []
	for i in range(len(atom1)):
		if (atom1[i] == atom2[i]):
			ans.append(atom1[i])
		elif (atom1[i] == -1):
			ans.append(atom2[i])
		elif (atom2[i] == -1):
			ans.append(atom1[i])
		else:
			return None
	return ans
	
#molecule[0] = a list of +atoms
#molecule[1] = a list of -atom	
def molecule_intersection(molecule1, molecule2):
	ans=[[],[]]
	if molecule1==None or molecule2==None:
		#print "Molecule1",molecule1,"Molecule2",molecule2
		return None
	for sign1 in range(2):
	  for sign2 in range(2):
		for i in range(len(molecule1[sign1])):
			for j in range(len(molecule2[sign2])):
				ret = atom_intersection(molecule1[sign1][i],molecule2[sign2][j])
				if ret != None:
					ans[sign1 ^ sign2].append(ret)
	return molecule_trim(ans)

#set is a list of atoms	

def merge_place(atom1, atom2):
	place = -1
	dif_num = 0
	for i in range(len(atom1)):
		if atom1[i] != atom2[i]:
			dif_num +=1
			if dif_num>1:
				return -1
			if atom1[i]!=-1 and atom2[i]!=-1:
				place=i
	if place>=6 and place<=69:
		return place
	else:
		return -1
				
#brute force a smarter idea is sort	
def set_merge(set):	
	find=True
	while find:
		find = False
		for i in range(len(set)):
			for j in range(i):
				place = merge_place(set[i],set[j])
				if place > 0:
					find=True
					set[j][place]=-1
					del set[i]
					break
			if find:
				break
	return set
		
					
	
def molecule_trim(ans):
	find = True
	ans[0]=set_merge(ans[0])
	ans[1]=set_merge(ans[1])
	while find:
		find = False
		for i in range(len(ans[0])):
			for j in range(len(ans[1])):
				if ans[0][i] == ans[1][j]:
					del ans[0][i]
					del ans[1][j]
					find = True
					break
			if find:
				break
	if (len(ans[1]) == 0) and (len(ans[0]) == 0):
		return None
	else:
		return ans
		
def molecule_minus(molecule1, molecule2):
	ans = molecule1
	intersection = molecule_intersection(molecule1,molecule2)
	if intersection != None:
		for atom in intersection[0]:
			ans[1].append(atom)
		for atom in intersection[1]:
			ans[0].append(atom)
	return molecule_trim(ans)

#rules[index] = molecule

def dag_generator(rules):
	dag = []
	for i in range(len(rules)):
		match_range=copy.deepcopy(rules[i])
		#print "loop on",i
		#print "---------------------------------"
		for j in range(i):
			#print "Comparing",match_range,"     and rule",j,":",rules[j]
			if molecule_intersection(match_range, rules[j])!=None:
				dag.append((i,j))
				match_range = molecule_minus(match_range,rules[j])
				#print "match changes to   ",match_range
				rules[j] = molecule_minus(rules[j],rules[i])
				#print "rule",j,"changes to   ",rules[j]
				if match_range == None:
					break
	return dag
	
def type_parse(fileName):
	fileHandle = open(fileName)
	types=[]
	lines = fileHandle.readlines()
	for line in lines:
		reg = re.compile(r'"(.+?)"')
		types.append(reg.findall(line)[0])
	fileHandle.close()
	return types
		
		
def rule_parse(types,filename):
	fileHandle = open(filename)
	rule_pattern = re.compile(r'pattern=([\s\S]*?)action=')
	content = fileHandle.read()
	#print content
	patterns = rule_pattern.findall(content)
	#print patterns
	rules=[]
	for line in patterns:
		rule=[]
		for type in types:
			pattern = type +'=(\d+?),'
			reg = re.compile(pattern)
			value = reg.findall(line)
			if len(value)==0:
				rule.append(-1)
			else: 
				rule.append(int(value[0]))
		#print rule
		rules.append([[rule],[]])
	return rules


def draw_dag(rules,dag):
    dg = nx.DiGraph()
    for i in range(len(rules)):
        dg.add_node(i)
    for p in dag:
        dg.add_edge(p[0],p[1])
    nx.draw_circular(dg)
    plt.show()


if __name__=="__main__":
	#parse all the types 
	types = type_parse("typename.txt")
	if len(sys.argv) != 2:
		print "Usage: python dag_generator.py rule_file_path"
		print "One pattern on each line in rule_file."
		sys.exit(0)
	rules = rule_parse(types,sys.argv[1])
	# fileHandle = open(sys.argv[1])
	# lines = fileHandle.readlines()
	# rules=[]
	# for line in lines:
		# atom = [int(i) for i in line.strip('\n').split(' ')]
		# #print atom
		# rules.append([[atom],[]])
	dag=dag_generator(rules)
	print dag
	#draw_dag(rules,dag)
