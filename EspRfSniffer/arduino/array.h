template <class TYPE>
class CArray
{
	TYPE	*m_arrElements;
	uint16_t	m_nCount;
	uint16_t	m_nMaxCount;

	typedef int (*TCompareFunction)(TYPE&, TYPE&);

public:
	CArray()
	{
	}

	CArray( TYPE *pSource, int nLength )
	{
		m_arrElements = pSource;
		m_nCount = 0;
		m_nMaxCount = nLength;
	}
	
	void Init( TYPE *pSource, int nLength )
	{
		m_arrElements = pSource;
		m_nCount = 0;
		m_nMaxCount = nLength;
	}

	bool IsEmpty()
	{
		assert( m_arrElements );
		return m_nCount == 0;
	}

	void Add(TYPE t)
	{
		assert( m_nCount < m_nMaxCount );
		m_arrElements[m_nCount++] = t;
	}

	TYPE &GetLast()
	{
		assert( m_nCount > 0 );
		return m_arrElements[m_nCount-1];
	}
    
	// returns pointer to existing element
	TYPE& RemoveLast()
	{
		assert( m_nCount > 0 );
		return m_arrElements[--m_nCount];
	}

	void Resize( int nDif )
	{
		m_nCount += nDif;
		assert( m_nCount >= 0 && m_nCount <= m_nMaxCount );
	}

	int GetSize() const
	{
		return m_nCount;
	}

	int GetMaxSize()
	{
		return m_nMaxCount;
	}

	void SetSize( int nSize )
	{
		m_nCount = nSize;
	}

	TYPE& operator []( int i)
	{
		if ( i < 0 )
			i += m_nCount;
		assert( i >= 0 && i < GetSize() );
		return m_arrElements[i];
	}

	const TYPE& operator []( int i) const
	{
		if ( i < 0 )
			i += m_nCount;
		assert( i >= 0 && i < GetSize() );
		return m_arrElements[i];
	}

	void RemoveAt( int i )
	{
		assert( i < GetSize() );
		for ( ; i < GetSize()-1; i++ )
			m_arrElements[i] = m_arrElements[i+1];
		Resize(-1);
	}

	void InsertAt( int i, const TYPE& element )
	{
		int nSize = GetSize();
		assert( i <= nSize );
		Resize(+1);

		for ( int j = nSize-1; j >= i; j-- )
			m_arrElements[j+1] = m_arrElements[j];
		m_arrElements[i] = element;
	}

	void RemoveAll()
	{
		m_nCount = 0;
	}

	void Sort(TCompareFunction fCompare)
	{
		for ( int i=0; i<m_nCount; i++)
			for ( int j=i+1; j<m_nCount; j++)
				if ( fCompare( m_arrElements[i], m_arrElements[j] ) < 0 ) 
				{
					TYPE tTemp = m_arrElements[i];
					m_arrElements[i] = m_arrElements[j];
					m_arrElements[j] = tTemp;
				}
	}
    
    int Find(TYPE& value)
    {
        for (int i=0; i<m_nCount; i++)
            if (m_arrElements[i] == value)
                return i;
        return -1;
    }

	TYPE* GetData()
	{
		return m_arrElements;
	}

    void Copy(const CArray<TYPE>& source)
    {
        SetSize(source.GetSize());
        for (int i=0; i<source.GetSize(); i++)
            m_arrElements[i] = source.m_arrElements[i];
    }
};
