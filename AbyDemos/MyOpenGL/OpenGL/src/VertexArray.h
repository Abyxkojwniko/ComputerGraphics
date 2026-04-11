#include "VertexBufferLayout.h"
#include "VertexBuffer.h"

class VertexArray {
private:
	unsigned int m_rendererID;
public:
	VertexArray();
	~VertexArray();

	void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void Bind() const;
	void Unbind() const;

};
