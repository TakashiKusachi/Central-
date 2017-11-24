#ifndef _RingBuff_HPP_
#define _RingBuff_HPP_

template<typename type,unsigned int size>
class RingBuff{
	type buff[size];
	
	unsigned short head;	//読出し位置
	unsigned short tall;	//書き出し位置
	
	unsigned int lenght;
	
	struct{
		bool full:1;
		bool empty:1;
	}Flags;
public:
	RingBuff(void)
	{
		head = tall = 0;
		lenght = size;
		Flags.empty = true;
		Flags.full = false;
	}
	int enqueue(type t)
	{
		if(isFull()){
			return -1;
		}
		buff[tall] = t;
		tall += 1;
		Flags.empty = false;
		
		if(tall == lenght)tall = 0;
		if(tall == head)Flags.full = true;
		
	}
	type dequeue(void)
	{
		type t;
		if(isEmpty()){
			return -1;
		}
		t = buff[head];
		head++;
		Flags.full = false;
		
		if(head == lenght)head = 0;
		if(head == tall)Flags.empty = true;
		
		return t;
	}
	bool isEmpty(void)
	{
		return Flags.empty;
	}
	bool isFull(void)
	{
		return Flags.full;
	}
	
};

#endif