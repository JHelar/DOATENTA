#pragma once

namespace U5{
	template<class KEY,class INFO>
	struct HashNode
	{
		KEY key;
		INFO info;
		HashNode<KEY,INFO> *next;

		HashNode()
		{
			next = nullptr;
		}

		HashNode(KEY key,INFO info)
		{
			this->key = key;
			this->info = info;
			next = nullptr;
		}
	};
}

